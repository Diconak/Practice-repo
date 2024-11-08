using Catalog.API.Entities;
using Catalog.API.Repositories;
using Microsoft.AspNetCore.Mvc;

namespace Catalog.API.Controllers
{
    //Ovim bukvalno zadajemo uloge i putanje do odredjenih backend radnji koje cemo izvrsavati na serveru
    // [] -> omogucavajau nam da ubacimo promenljivu koja ono samo pretrazuje u kodu i menja je sa onim sto je pored nje
    [ApiController]
    [Route("api/v1/[controller]")]
    public class CatalogController : ControllerBase
    {
        IProductRepostories _repository; 
        // U sustini, stavljamo ovaj repozitorijum da mi bismo mogli samo direktno preko interfejsa da pristupamo nekoj bazi
        // A da ne moramo 100 puta da menjamo neku bazu ako zelimo da menjamo
        CatalogController(IProductRepostories repository) { 
            _repository = repository ?? throw new ArgumentNullException(nameof(repository));
        }

        //Ovde smo doslovno napravili get request koji koristi difoltnu putanju, i prilikom uspega ispisuje ocekivan izlaz
        [HttpGet]
        [ProducesResponseType(typeof(IEnumerable<Product>), StatusCodes.Status200OK)]
        public async Task<ActionResult<IEnumerable<Product>>> GetProducts() { 
        
            var products = await _repository.GetProducts();
            return Ok(products);
        }
    }
}
